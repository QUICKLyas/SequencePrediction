def create_dict_note(flag: bool, message: str = "",data: list = None) -> dict:
    dict_note = {}
    dict_note.setdefault("message", message)
    dict_note.setdefault("data", data)
    dict_note.setdefault("flag", flag)
    if flag:
        dict_note.setdefault("status", "success")
    else:
        dict_note.setdefault("status", "failure")
    return dict_note
