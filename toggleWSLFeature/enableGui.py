setting_file = "/mnt/c/Users/Shafayet/.wslconfig"
setting_name = "guiApplications="

with open(setting_file, "r+") as file:
    s = file.read()
    new = ""
    if s.find(setting_name + "false") != -1:
        new = s.replace(setting_name + "false", setting_name + "true")
        print("GUI Mode Enabled!")
    else:
        new = s.replace(setting_name + "true", setting_name + "false")
        print("GUI Mode Disabled!")

    file.seek(0)
    file.write(new)
    file.truncate()
