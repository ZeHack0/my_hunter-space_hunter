#!/bin/bash
# Lance Space Hunter compilé dans Docker (généré par `make docker`).
IMAGE=space_hunter
ARGS=(--rm -i)
[ -t 0 ] && ARGS+=(-t)

if ! docker image inspect "$IMAGE" >/dev/null 2>&1; then
    echo "Image introuvable, lance d'abord : make docker" >&2
    exit 84
fi

# -h n'a pas besoin d'affichage
if [ "$1" != "-h" ]; then
    case "$(uname -s)" in
    Linux)
        if [ -d /mnt/wslg ]; then   # Windows (WSL2 + WSLg)
            ARGS+=(-e DISPLAY="$DISPLAY" -v /tmp/.X11-unix:/tmp/.X11-unix
                   -v /mnt/wslg:/mnt/wslg -e PULSE_SERVER=unix:/mnt/wslg/PulseServer
                   -e ALSOFT_DRIVERS=pulse)
        else
            xhost +local:docker >/dev/null 2>&1
            ARGS+=(-e DISPLAY="${DISPLAY:-:0}" -v /tmp/.X11-unix:/tmp/.X11-unix)
            [ -e /dev/dri ] && ARGS+=(--device /dev/dri)
            PULSE="${XDG_RUNTIME_DIR:-/run/user/$(id -u)}/pulse"
            if [ -S "$PULSE/native" ]; then
                ARGS+=(-v "$PULSE:/run/pulse" -e PULSE_SERVER=unix:/run/pulse/native
                       -e ALSOFT_DRIVERS=pulse)
            else
                ARGS+=(-e ALSOFT_DRIVERS=null)
            fi
        fi ;;
    Darwin)                         # macOS : XQuartz requis
        if [ ! -d /Applications/Utilities/XQuartz.app ] && [ ! -d /Applications/XQuartz.app ]; then
            echo "Installe XQuartz : brew install --cask xquartz (puis déconnecte/reconnecte-toi)" >&2
            exit 84
        fi
        defaults write org.xquartz.X11 nolisten_tcp -bool false
        defaults write org.xquartz.X11 enable_iglx -bool true
        open -a XQuartz
        X11=/opt/X11/bin
        export DISPLAY="${DISPLAY:-:0}"
        # Attend que XQuartz soit prêt
        for _ in $(seq 1 30); do
            "$X11/xauth" nlist :0 2>/dev/null | grep -q . && break
            sleep 0.5
        done
        # Cookie XQuartz passé au conteneur (famille "wildcard" = valable quelle que soit l'IP)
        XAUTH_FILE="$HOME/.space_hunter.xauth"
        rm -f "$XAUTH_FILE"; touch "$XAUTH_FILE"
        "$X11/xauth" nlist :0 2>/dev/null | sed -e 's/^..../ffff/' \
            | "$X11/xauth" -f "$XAUTH_FILE" nmerge - 2>/dev/null
        if [ ! -s "$XAUTH_FILE" ]; then
            echo "XQuartz n'est pas prêt. Ferme-le (Cmd+Q) puis relance ./space_hunter." >&2
            exit 84
        fi
        # Son : PulseAudio (brew install pulseaudio) sinon jeu muet
        if command -v pulseaudio >/dev/null 2>&1; then
            pulseaudio --check 2>/dev/null || pulseaudio --daemonize=yes --exit-idle-time=-1 \
                --load="module-native-protocol-tcp port=4713 auth-ip-acl=127.0.0.1;192.168.0.0/16;172.16.0.0/12;10.0.0.0/8;0.250.250.0/24 auth-anonymous=1" \
                >/dev/null 2>&1
            ARGS+=(-e PULSE_SERVER=tcp:host.docker.internal:4713 -e ALSOFT_DRIVERS=pulse,null)
        else
            ARGS+=(-e ALSOFT_DRIVERS=null)
        fi
        docker run "${ARGS[@]}" \
            -e DISPLAY=host.docker.internal:0 -e LIBGL_ALWAYS_INDIRECT=1 \
            -e XAUTHORITY=/tmp/.Xauthority -v "$XAUTH_FILE:/tmp/.Xauthority:ro" \
            "$IMAGE" "$@"
        exit $? ;;
    *)
        echo "OS non supporté : sous Windows, lance-le depuis WSL2." >&2
        exit 84 ;;
    esac
fi

exec docker run "${ARGS[@]}" "$IMAGE" "$@"
