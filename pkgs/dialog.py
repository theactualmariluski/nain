import os

class Dialog:
    def __init__(self):
        print("Dialog successfully imported!")
    
    def CreateMsgBox(self, title, message):
        os.system(f"dialog --title \"{title}\" --msgbox \"{message}\" 10 40")

    
    def CreateYesOrNo(self, title, message, width=40, height=10):
        os.system(f"dialog --title \"{title}\" --yesno \"{message}\" {height} {width}")
        
    
    def CreateInput(self, title, message):
        os.system(f"dialog --title \"{title}\" --inputbox \"{message}\" 10 40")
  
