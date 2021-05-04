#!/usr/bin/python3
""" Count subreddits with key words """
import sys
import requests


def count_words(subreddit, word_list, after="", count=0, list_dict={}):
    """ Count words """
    stuff = {'User-Agent':
             'Mozilla/5.0'}
    link = "https://www.reddit.com/r/{}".format(subreddit)
    if list_dict == {}:
        for word in word_list:
            try:
                list_dict[str(word.lower())]
                word_list.remove(word)
            except Exception:
                list_dict[word.lower()] = 0
    if after == "":
        info = requests.get('{}/hot.json?limit=1'.format(
            link), allow_redirects=False, headers=stuff)
    else:
        info = requests.get(
            '{}/hot.json?limit=1&after={}&count={}'.format(
                link, after, count),
            allow_redirects=False, headers=stuff)
    if info.status_code == 200:
        info = info.json()
        if len(info.get('data').get('children')) == 0:
            for key, value in list_dict.items():
                print("{}: {}".format(key, value))
            return
        post = info.get('data').get('children')[0].get('data')
        title = post.get('title')
        title = title.split(" ")
        for i in range(len(title)):
            title[i] = title[i].lower()
        after = info.get('data').get('after')
        count = count + 1
        for word in word_list:
            if word.lower() in title:
                list_dict[str(word.lower())] = list_dict[str(word.lower())] + 1
        if after is not None:
            count_words(subreddit, word_list, after, count, list_dict)
        else:
            for key, value in list_dict.items():
                print("{}: {}".format(key, value))
            return
