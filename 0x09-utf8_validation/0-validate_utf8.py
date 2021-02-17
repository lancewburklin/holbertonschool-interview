#!/usr/bin/python3
""" Checking if data is UTF-8 valid """


def validUTF8(data):
    for i in data:
        if i > 255:
            return False
        try:
            str(i).encode("utf-8").decode("utf-8")
        except UnicodeDeocdeError:
            return False
    return True
