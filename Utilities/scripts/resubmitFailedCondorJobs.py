#!/usr/bin/env python
import glob
import re
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("-s", "--submit_file", type=str,
        default="submit.jdl", help="Original submit file")
parser.add_argument("-o", "--resubmit_file", type=str,
        default="resubmit.jdl", help="Submit file name for resumission")
parser.add_argument("-l", "--log_dir", type=str,
        default="logs", help="Submit file name for resumission")

args = parser.parse_args()

failed_ids = []
for logfile in glob.glob(args.log_dir+"/*.log"):
    contents = ""
    with open(logfile, "r") as log:
        contents = log.read()

    if "return value 0" not in contents:
        procid = re.findall(r"\d+", logfile)
        if len(procid) > 1:
            raise ValueError("Can't find the process ID from" + \
                    "logfile name for file %s." % logfile)
        failed_ids.append(procid[0]) 
print "Found %i failed jobs to resumit" % len(failed_ids)

submit_info = []
with open(args.submit_file) as submit_file:
    submit_info = submit_file.readlines()
with open(args.resubmit_file, "w") as resubmit:
    for line in submit_info:
        if "nprocesses" in line.lower() or "queue" in line.lower():
            continue
        resubmit.write(line.replace("Process", "Item"))
    resubmit.write("Queue 1 in " + ",".join(failed_ids))

