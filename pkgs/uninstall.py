import os
from dialog import Dialog

def uninstall(name):
    di = Dialog()
    # CreateYesOrNo returns 0 if "Yes" is selected, 1 for "No"
    if di.CreateYesOrNo("Uninstalling", f"Are you sure you want to uninstall {name}?") == 0:
        # Expanding the $HOME path
        path = os.path.expanduser(f"~/.local/nainlibs/{name}")
        
        # Check if the file exists before removing
        if os.path.exists(path):
            os.remove(path)
            di.CreateMsgBox("Uninstalled", f"{name} has been uninstalled!")
        else:
            di.CreateMsgBox("Error", f"{name} not found!")
    else:
        di.CreateMsgBox("Cancelled", "Uninstallation was cancelled.")

if __name__ == "__main__":
    di = Dialog()
    msg = di.CreateInput("Uninstall", "Enter the name of the package to uninstall:")
    uninstall(msg)
    