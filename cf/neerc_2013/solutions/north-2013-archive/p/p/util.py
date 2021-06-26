import os
import sys
import shutil
import subprocess

import log

windows = os.name == "nt"
options = None
swd = os.getcwd()

def relswd(path):
    return os.path.abspath(os.path.join(swd, path))

root = os.path.abspath(sys.argv[0] + "/../../../")
def relpath(path):
    return os.path.abspath(root + "/" + path)

def replaceSuffix(filename, newSuffix = ""):
    return deleteSuffix(filename) + newSuffix

def deleteSuffix(filename):
    return ".".join(filename.split(".")[:-1])

def cwdirname():
    return os.path.dirname(os.getcwd())

def cwbasename():
    return os.path.basename(os.getcwd())

def copyToDir(file, dir):
    shutil.copy(file, join(dir, file))

def removeFiles(*files):
    list(map(os.remove, filter(os.path.exists, files)))

def removeDirs(*files):
    list([shutil.rmtree(f, True) for f in files if os.path.exists(f)])

def cleanDirs(*files):
    removeDirs(*files)
    mkdirs(*files)

def appendFile(filename, message, *args):
    with open(filename, "a") as file:
        file.write(message.format(*args))
        file.write("\n")

def writeFile(filename, message, *args, **kwargs):
    with open(filename, "w") as file:
        file.write(message.format(*args, **kwargs))
        file.write("\n")

def concatFiles(target, *sources):
    with open(target, "ab") as targetFile:
        for source in filter(os.path.exists, sources):
            with open(source, "rb") as sourceFile:
                shutil.copyfileobj(sourceFile, targetFile)
            os.remove(source)

def readLines(filename):
    with open(filename) as file:
        return list(file.readlines())

def listdir(dirname):
    if os.path.exists(dirname) and os.path.isdir(dirname):
        return os.listdir(dirname)
    else:
        return []

def execute(*command, **kwargs):
    log.debug("Run: {}", ' '.join(command))
    try:
        return subprocess.call(command, **kwargs)
    except OSError as e:
        log.error('Error running "{}"', ' '.join(command))
        raise

def mkdirs(*dirs):
    for file in dirs:
        if not os.path.exists(file):
            os.makedirs(file)

def join(*parts):
    return os.path.join(*parts).replace("\\", "/")
