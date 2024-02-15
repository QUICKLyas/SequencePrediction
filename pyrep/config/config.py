from fake_useragent import UserAgent as ua
request_header = {
    'Accept': "*/*",
    'Accept-Encoding': "gzip, deflate, br",
    'Accept-Language': "zh-CN,zh;q=0.9",
    'Connection': "keep-alive",
    'Cookie': "_gid=GA1.2.634482299.1707640231; PHPSESSID=tevlmt4j56o6s5sh4odnko7s56; "
              "Hm_lvt_692bd5f9c07d3ebd0063062fb0d7622f=1707640231,1707725268,1707815517; "
              "Hm_lvt_12e4883fd1649d006e3ae22a39f97330=1707640231,1707725268,1707815518; _gat_UA-66069030-3=1; "
              "Hm_lpvt_692bd5f9c07d3ebd0063062fb0d7622f=1707815520; _ga=GA1.2.1291511736.1707640231; "
              "Hm_lpvt_12e4883fd1649d006e3ae22a39f97330=1707815520; "
              "_ga_9FDP3NWFMS=GS1.1.1707815517.6.1.1707815534.0.0.0",

    'Host': "jc.zhcw.com",
    'Referer': "https://jc.zhcw.com",
    'Sec-Ch-Ua': "\"Not A(Brand\";v=\"99\", \"Google Chrome\";v=\"121\", \"Chromium\";v=\"121\"",
    'Sec-Ch-Ua-Mobile': "?0",
    'Sec-Ch-Ua-platform': "windows",
    'Sec-Fetch-Dest': "script",
    'Sec-Fetch-Mode': "no-cors",
    'Sec-Fetch-Site': "same-site",
    'User-Agent': str(ua.random)
}
general = {
    'Request URL': "https://jc.zhcw.com/port/client_json.php?callback=jQuery112205363190356763174_1707823032916"
                   "&transactionType=10001001&lotteryId=281&issueCount=1000&startIssue=&endIssue=&startDate=&endDate"
                   "=&type=0&pageNum=",
    'pageNum': 1,
    'pageSize': "&pageSize=30",
    'end': "&tt=0.9988052553151698&_=1707823032919",
    'Request Method': "GET",
}
# total pages (0~33)
pages = 33
# file name for data
