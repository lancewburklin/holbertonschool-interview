#!/usr/bin/python3


def validUTF8(data):
    for i in data:
        if i > 255:
            return False
        try:
            str(i).encode("utf-8").decode("utf-8")
        except UnicodeDeocdeError:
            return False
    return True
