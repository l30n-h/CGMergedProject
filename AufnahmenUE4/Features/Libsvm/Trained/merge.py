#!/usr/bin/python

import sys
import os
from shutil import copyfile
from os import listdir
from os.path import isfile, join
import re

featureDir = "../.."
files = [f for f in listdir(featureDir) if isfile(join(featureDir, f))]
fileMap = {}
for f in files:
	if f.endswith(".feat"):
		fileMap.setdefault(re.sub('\d', '', f.lower()), []).append(f)
trainingFiles = []
testingFiles = []
for key in fileMap:
	values = fileMap[key]
	for i, v in enumerate(values):
		if i%2 == 0:
			trainingFiles.append(v)
		else:
			testingFiles.append(v)


def concatFiles(inFiles, outFile):
	with open(outFile, 'w') as out:
		for f in inFiles:
			with open(f) as curFile:
				for line in curFile:
					out.write(line)
	return

concatFiles(map(lambda x: join(featureDir, x), trainingFiles), "features.training")
concatFiles(map(lambda x: join(featureDir, x), testingFiles), "features.test")
concatFiles(["features.training", "features.test"], "features.all")
if isfile(join(featureDir, "FeatureNameLabelMapping.txt")):
	copyfile(join(featureDir, "FeatureNameLabelMapping.txt"), "FeatureNameLabelMapping.txt")
