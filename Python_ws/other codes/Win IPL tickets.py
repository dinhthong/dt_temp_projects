# https://www.quora.com/What-are-the-best-Python-scripts-youve-ever-written
import pickle
import time
import urllib2
import urllib
import random
import thread
from p_friends import data as friends
url = "https://www.afancan.com/thefanstation/happinesswall/api/castVotefb.php"
TIME_LOWER_LIMIT = 2
TIME_UPPER_LIMIT = 10
def go_fish(friends):
    for friend in friends:
        req = urllib2.Request(url)
        #req = urllib2.Request("Page on Localhost")
        req.add_header('Accept', '*/*')
        # req.add_header('Accept-Encoding', 'gzip, deflate')
        req.add_header('Content-Type','application/x-www-form-urlencoded; charset=UTF-8')
        req.add_header('Cookie', 'a very long cookie')
        req.add_header('Host', 'Page on Afancan')
        req.add_header('Referer','http://www.afancan.com/thefanstation/happinesswall/')
        req.add_header('User-Agent', 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:12.0) Gecko/20100101 Firefox/12.0')
        req.add_header('X-Requested-With', 'XMLHttpRequest')
        s = urllib2.urlopen(req, urllib.urlencode({'m':'1116591190', 'uid':friend['id']}))
        print "%s(%s) voted with response as %s" % (friend['name'], friend['id'], s.read())
        # time.sleep(random.randint(TIME_LOWER_LIMIT, TIME_UPPER_LIMIT))
try:
    thread.start_new_thread(go_fish, (friends[ : len(friends)/5],))
    thread.start_new_thread(go_fish, (friends[len(friends)/5 : 2*len(friends)/5],))
    thread.start_new_thread(go_fish, (friends[2*len(friends)/5 : 3*len(friends)/5],))
    thread.start_new_thread(go_fish, (friends[3*len(friends)/5 : 4*len(friends)/5],))
    thread.start_new_thread(go_fish, (friends[4*len(friends)/5 : ],))
except:
    print "Unable to start thread"
while 1:
    pass