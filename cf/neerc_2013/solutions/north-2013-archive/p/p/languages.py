import os
from languages_util import *
import defaults
import util

testlib = util.relpath("testlib")

exe = ".exe" if util.windows else ""
def gnu(compiler):
    return [
        compiler, "-O2", "{program}", "-I" + testlib, "-o", "{programNoSuffix}" + exe
    ] + (["-Wl,--stack=67108864"] if util.windows else [])

languages = [
    language(".java", "Java", comments_c,
        javaToJar,
        addArgs(lambda program: runJar(util.replaceSuffix(program, ".jar")))
    ),
    compiled(".dpr", "Borland Delphi", comments_pascal,
        ["dcc32", "-m", "-cc", "-U" + testlib, "{program}"]
    ),
    compiled(".pp", "Free Pascal", comments_pascal,
        ["fpc", "-Fu" + testlib, "{program}"]
    ),
    compiledWinLin(".c", "C", comments_c,
        ["cl", "/O2", "-I" + testlib, "{program}"],
        gnu("gcc"),
        tempSuffixes = [".obj", ".o"]
    ),
    compiled(".cc", "GNU C", comments_c,
        gnu("gcc"),
        tempSuffixes = [".obj", ".o"]
    ),
    compiledWinLin(".cpp", "C++", comments_c,
        ["cl", "/O2", "/EHsc", "-I" + testlib, "{program}"],
        gnu("g++"),
        tempSuffixes = [".obj", ".o"]
    ),
    compiled(".c++", "GNU C++", comments_c,
        gnu("g++"),
        tempSuffixes = [".o"]
    ),
    compiled(".cs", "C#", comments_c,
        ["csc", "/o", "/platform:x86", "{program}"]
    ),
    compiled(".vb", "Visual Basic", comments_basic,
        ["vbc", "/platform:x86", "{program}"]
    ),
    compiled(".hs", "Haskell", comments_haskell,
        ["ghc", "--make", "{program}"]
    ),
    compiled(".ml", "OCaml", comments_pascal,
        ["ocamlopt", "{program}", "-o", "{programNoSuffix}.exe"]
    ),
    script(".py", "Python", comments_python,
        ["python", "{program}"]
    ),
    script(".cmd", "Windows command interpreter", comments("rem #", "#", "#"),
        ["cmd", "/c", "{program}"]
    ),
    script(".exe", "Windows executable", None,
        ["{program}"]
    ),
    language(".class", "Java .class files", None,
        noCompile,
        addArgs(lambda program: java(defaults.javaClasspath + ["."], [util.deleteSuffix(program)]))
    ),
    language(".jar", "Java .jar files", None,
        noCompile,
        addArgs(runJar)
    ),
]
