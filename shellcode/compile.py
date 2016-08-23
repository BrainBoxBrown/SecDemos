#!/usr/bin/python
import sys, os, re, subprocess
 
objname = "pobj.o"
binname = "pbin"
 
def generateBinary(asm_filename):
    cmd = ['nasm', '-f', 'elf32', asm_filename, '-o', objname]
    try:
        val = subprocess.check_output(cmd, stderr=subprocess.STDOUT)
        if(len(val) > 0):
            print "Generation output\n%s" % (val),
        try:
            ldcmd = ['ld', objname, '-m', 'elf_i386', '-o', binname]
            val = subprocess.check_output(ldcmd, stderr=subprocess.STDOUT)
            if(len(val) > 0):
                print "Linking output\n%s" % (val),
        except subprocess.CalledProcessError as e:
            errstr = "Failed to generate asm object file\n"
            errstr +=  (str(e.output).strip())
            raise ValueError(errstr)
 
    except subprocess.CalledProcessError as e:
        errstr = "Failed to generate asm object file\n"
        errstr += "'%s'" % (str(e.output).strip())
        raise ValueError(errstr)
 
def extractPayload():

        val = subprocess.check_output(["objdump", "-d", binname])
        res = val.partition(r"_start")[2]
        res = re.sub(r".*:\w*(.*)", r"\1", res)
        print res
        lines = res.split("\n")
        bytes = []
        for x in lines:
            if '   ' in x:
                index = x.index('   ')
                r = re.findall(r"([a-f0-9]{2}) ", x[:index+1])
                print x[:index]
                print r
                bytes += r

        # res = '\n'.join([ " " + x.strip()[:]  ])
        # res = res.replace('dec', '') #pesky problem hot fix
        print bytes

        # res = re.findall(r"([a-f0-9]{2}) ", res)
        # print res

        print "len: {0}".format(len(bytes))

        print "__SHELLCODE__ = [ "
        print ''.join([ '\\x' + x.strip() for x in bytes]),
        print "];",
 
        print "__SHELLCODE__ = [ "
        print ''.join([ '\'\\x' + x.strip() + '\', ' for x in bytes]),
        print "];",

 
def cleanup(rmbinary=False):
    if os.path.isfile(objname):
        os.remove(objname)
    if rmbinary == True:
        if os.path.isfile(binname):
            os.remove(binname)
 
def usage():
    print "./shellcodegen [nasm_asm_file.asm]"
    print "Currently only accepts i386 shellcode"
 
def main():
    if len(sys.argv) != 2:
        usage()
        exit(1)
 
    try:
        print "Generating files for extraction..."
        generateBinary(sys.argv[1])
        print "Extracting payload...\n"
        extractPayload()
        print "\n\nShellcode located in pbin"
        cleanup()
 
    except ValueError as e:
        print str(e),
        cleanup(rmbinary=True)
 
main()
