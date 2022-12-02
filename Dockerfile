FROM qmkfm/qmk_cli

VOLUME /qmk_firmware
WORKDIR /qmk_firmware

COPY requirements.txt .
RUN pip install -r requirements.txt

CMD qmk compile -kb all -km default
