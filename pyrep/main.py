from webrep import WebRep

# 但程序写入内容
page = 1
web_rep = WebRep()
list_data = web_rep.parse_text(web_rep, web_rep.get_html_text(page=page))
web_rep.write_text(web_rep, list_data)

