import argparse
import logging
import os
import subprocess
import sys

FORMATTER = "%(levelname)s - %(message)s"
logger = logging.getLogger("mylogger")
logger.setLevel(logging.DEBUG)

fh = logging.FileHandler("run.log")
fh.setLevel(logging.DEBUG)

ch = logging.StreamHandler()
ch.setLevel(logging.DEBUG)

formatter = logging.Formatter(FORMATTER)
fh.setFormatter(formatter)
ch.setFormatter(formatter)
logger.addHandler(fh)
logger.addHandler(ch)


def parse():
    parser = argparse.ArgumentParser(description="script")

    parser.add_argument("path", type=str, help="path")
    parser.add_argument("command", type=str, help="command")
    parser.add_argument("-t", "--test", type=str, nargs="*", help="test case")
    parser.add_argument("-i", "--input", action="store_true", help="input")

    args = parser.parse_args()
    if args.input:
        args.input_content = input("Input:\n")
    logger.info(
        "Path: %s - Command: %s - Input: %s",
        args.path,
        args.command,
        args.input_content,
    )
    return args


def run_process(
    command: list, out_meg: str, err_meg: str, intput_bytes: bytearray = bytearray()
):
    run_process = subprocess.Popen(
        command, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE
    )
    run_process.stdin.write(intput_bytes)
    out, err = run_process.communicate()
    if run_process.returncode != 0:
        logger.debug("%s - Err: %s", err_meg, err.decode())
    else:
        logger.debug("%s - Out: %s", out_meg, out.decode())


logger.info("START")
args = parse()

OUTPUT_FILE = "run"
compile_command = ["g++", "-o", OUTPUT_FILE]
compile_command.append(args.path)

run_process(
    command=compile_command, out_meg="Compile success", err_meg="Compile failed"
)


# Command to execute the compiled program
run_command = ["./" + OUTPUT_FILE]
run_process(
    command=run_command,
    out_meg="Run success",
    err_meg="Run failed",
    intput_bytes=bytearray(args.input_content, encoding="utf8"),
)


os.remove(OUTPUT_FILE)
logger.info("Clean")
logger.info("END")
