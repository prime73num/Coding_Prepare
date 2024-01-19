import argparse
import logging
import os
import subprocess
import yaml

FORMATTER = "%(levelname)s - %(message)s"
LOGGER = logging.getLogger("mylogger")
LOGGER.setLevel(logging.DEBUG)

fh = logging.FileHandler("run.log")
fh.setLevel(logging.DEBUG)

ch = logging.StreamHandler()
ch.setLevel(logging.DEBUG)

formatter = logging.Formatter(FORMATTER)
fh.setFormatter(formatter)
ch.setFormatter(formatter)
LOGGER.addHandler(fh)
LOGGER.addHandler(ch)


def parse():
    parser = argparse.ArgumentParser(description="script")

    parser.add_argument("command", type=str, help="command")
    parser.add_argument("path", type=str, help="path")
    parser.add_argument("-t", "--test", type=int, nargs="*", default=[0], help="test case")

    args = parser.parse_args()
    LOGGER.info(
        "Path: %s - Command: %s - Test: %s",
        args.path,
        args.command,
        args.test[0]
    )
    return args


def run_process(
    command: list, intput_bytes: bytearray = bytearray()
):
    run_process = subprocess.Popen(
        command, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE
    )
    run_process.stdin.write(intput_bytes)
    out, err = run_process.communicate()
    return run_process.returncode, out, err


def load_testcases(file: str):
    stream = open(file, 'r')
    testcases = yaml.safe_load(stream)
    return testcases

def gettestcase(file: str, testnum: int, Tests):
    path = file.split('/')
    path[2] = path[2][:4]
    case = Tests[path[1]][path[2]][testnum]
    return case

def runtest(command: list, file: str, testnum: int, Tests):
    case = gettestcase(file, testnum, Tests)
    input = bytearray(case["input"], encoding="utf8")
    rcode, out, err = run_process(command, input)
    if rcode != 0:
        LOGGER.debug("Run failed")
        print("Err:")
        print(err.decode())
        return
    if out.decode() == case["output"]:
        LOGGER.debug("Case %d Passed", testnum)
    else:
        LOGGER.debug("Case %d Failed", testnum)
        print("Output:")
        print(out.decode())
        print("Risht:")
        print(case["output"])


    return


LOGGER.info("START")
testfile = "testcases.yaml"
Tests = load_testcases(testfile)
args = parse()

OUTPUT_FILE = "run"
compile_command = ["g++", "-o", OUTPUT_FILE]
compile_command.append(args.path)

run_process(
    command=compile_command
)


run_command = ["./" + OUTPUT_FILE]
runtest(
    run_command,
    args.path,
    args.test[0],
    Tests
)


os.remove(OUTPUT_FILE)
LOGGER.info("Clean")
LOGGER.info("END")
