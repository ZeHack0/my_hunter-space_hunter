# Space Hunter — compilation avec la CSFML
FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive \
    ALSOFT_DRIVERS=null

RUN apt-get update && apt-get install -y --no-install-recommends \
        build-essential make libcsfml-dev libgl1-mesa-dri \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

# Pas de -march=native : l'image doit tourner sur toutes les machines
RUN sed -i 's/^CFLAGS += -m\(arch\|tune\)=native/# &/' flags.mk \
    && make SHELL=/bin/bash fclean \
    && make SHELL=/bin/bash

ENTRYPOINT ["./space_hunter"]
