# -*- mode: python ; coding: utf-8 -*-

block_cipher = None

a = Analysis(
    ['update.py'],
    pathex=['F:/IDE/_CodeSpace/SequencePrediction'],
    binaries=[],
    datas=[],
    hiddenimports=[
        'pyrep',
        'pyrep.config',
        'pyrep.config.config'
        'pyrep.config.file_config',
        'pyrep.config.mongo_config',
        'pyrep.data',
        'pyrep.util',
        'pyrep.util.file',
        'pyrep.util.mongo',
        'pyrep.util.note',
        'pyrep.reptile',
        'pyrep.reptile.db',
        'pyrep.reptile.webrep',
        'pyrep.reptile.prothread',],
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
