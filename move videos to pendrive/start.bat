@echo off
cd /d "C:\Users\Shafayet\move videos to pendrive"
python v0.2.py
PowerShell -Command "eject-usb"
PowerShell -Command "New-BurntToastNotification -Text 'File Transfer Completed!' -AppLogo 'D:\icon\HD_USB.ico'"
PowerShell -Command "eject-usb"
exit
