import requests
import json
from pyrep.util import file as u_file
from pyrep.config import config as cfg


class WebRep:
    def __init__(self):
        req_url = cfg.general
        self.url_start = req_url.get('Request URL')
        self.url_pageN = req_url.get('pageNum')  # <int>
        self.url_end = req_url.get('pageSize')+req_url.get('end')
        self.header = cfg.request_header
        self.range = cfg.pages

    def get_html_text(self, page: int = 0) -> list:
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
    def parse_text(self, list_data: list) -> list:
        data = []
        for item in list_data:
            # ['frontWinningNum'] ['backWinningNum']
            front_winning_num = item['frontWinningNum']
            back_winning_num = item['backWinningNum']
            issue = item['issue']
            open_time = item['openTime']
            step = 3
            list_item = []
            # 0-2 3-5 6-8 9-11 12-14
            index_start = 0
            index_end = 2
            while index_end < 15:
                int_num = int(front_winning_num[index_start:index_end])
                list_item.append(int_num)
                index_start += step
                index_end += step
            index_start = 0
            index_end = 2

            while index_end < 6:
                int_num = int(back_winning_num[index_start:index_end])
                list_item.append(int_num)
                index_start += step
                index_end += step
            dict_data = {
                'issue': issue,
                'openTime': open_time,
                'WinningNum': list_item
            }
            data.append(dict_data)
        # for item in data:
        #     print(item)
        return data

    @staticmethod
    def write_text(self, list_data: list, file: str = "") -> bool:
        if len(list_data) == 0:
            return False
        # write data into file (name "dataKJHM.json") dictionary_list
        bool_flag: bool
        if file == "":
            bool_flag = u_file.write_json_file(list_data)
        else:
            bool_flag = u_file.write_json_file(list_data, file)
        if not bool_flag:
            self.write_text(list_data=list_data)
        return True

