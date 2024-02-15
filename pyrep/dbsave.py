

# use mongodb
class DBSave:
    def __init__(self):
        pass

    def save_data(self, list_data: list):
        pass

    def delete_data(self, index:int=0):
        pass

    def get_data_index(self,list_data_key: str=None) -> int:
        pass

    def get_data_item(self,index:int=0) -> dict:
        pass

    def update_item(self,index:int=0) -> bool:
        pass

    def get_all(self,page:int=0,page_size:int=30) -> list:
        pass
