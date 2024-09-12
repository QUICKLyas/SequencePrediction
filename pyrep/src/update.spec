# -*- mode: python ; coding: utf-8 -*-

block_cipher = None

a = Analysis(
    ['update.py'],
    pathex=['F:/IDE/_CodeSpace/SequencePrediction/pyrep'],
    binaries=[],
    datas=[],
    hiddenimports=[
        'src',
        'src.config',
        'src.config.config'
        'src.config.file_config',
        'src.config.mongo_config',
        'src.data',
        'src.util',
        'src.util.file',
        'src.util.mongo',
        'src.util.note',
        'src.reptile',
        'src.reptile.db',
        'src.reptile.webrep',
        'src.reptile.prothread',],
    hookspath=[],
    runtime_hooks=[],
    excludes=[],
    win_no_prefer_redirects=False,
    win_private_assemblies=False,
    cipher=block_cipher,
    noarchive=False,
)
pyz = PYZ(a.pure, a.zipped_data, cipher=block_cipher)

exe = EXE(
    pyz,
    a.scripts,
    a.binaries,
    a.datas,
    [],
    name='update',
    debug=False,
    bootloader_ignore_signals=False,
    strip=False,
    upx=True,
    upx_exclude=[],
    runtime_tmpdir=None,
    console=True,
    disable_windowed_traceback=False,
    argv_emulation=False,
    target_arch=None,
    codesign_identity=None,
    entitlements_file=None )
