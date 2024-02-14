import requests
from bs4 import BeautifulSoup
import config as cfg
import json
import time


class WebRep:
    def __init__(self):
        req_url = cfg.general
        self.url_start = req_url.get('Request URL')
        self.url_pageN = req_url.get('pageNum')  # <int>
        self.url_end = req_url.get('pageSize')+req_url.get('end')
        self.header = cfg.request_header
        self.range = cfg.pages

    def get_html_text(self, page=0) -> list:
        index = self.url_pageN + page
        if index < self.range:
            uri = self.url_start + str(self.url_pageN + page) + self.url_end
            response = requests.get(uri,headers=self.header)
            string_res = response.text
            string_json = string_res[string_res.index('(')+1:len(string_res)-1]
            dict_data = json.loads(string_json)
            list_data = dict_data['data']
        else:
            list_data = []
        return list_data

    @staticmethod
    def parse_text (self, list_data: list) -> list:
        data = []
        for item in list_data:
            # ['frontWinningNum'] ['backWinningNum']
            front_winning_num = item['frontWinningNum']
            back_winning_num = item['backWinningNum']
            index_start = 0
            index_end = 2
            step = 3
            list_item = []
            while index_end < 14:
                # 0-2 3-5 6-8 9-11 12-14
                int_num = int(front_winning_num[index_start:index_end])
                list_item.append(int_num)
                index_start += step
                index_end += step
            index_start = 0
            index_end = 2
            while index_end < 5:
                int_num = int(back_winning_num[index_start:index_end])
                list_item.append(int_num)
                index_start += step
                index_end += step
            data.append(list_item)
        for item in data:
            print(item)
        return data

    def write_text(self, list_data: list) -> None:
        pass

