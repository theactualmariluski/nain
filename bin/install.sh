#!/run/current-system/sw/bin/bash

# This script is used to install the latest version of Nain from GitHub
# It also manages the versions of Nain if there are more than one installed
# Hope you enjoy it!

echo "Loading the Nain Version Manager and package manager..."

installVersion() {
    local opts=(1 "Add a new version" 2 "Remove a version" 3 "Exit")
    
    if [ $? -eq 0 ]; then  
        case $CHOICE in  
            1)
                dialog --inputbox "Enter the GitHub URL of the Nain version you want to install:" 0 0 2>&1 >/dev/tty
                ;;
            2)
                echo "Removing a version..."
                ;;
            3)
                echo "Exiting..."
                ;;
            *)  # Added: Catch-all case for unexpected input
                echo "Invalid option selected."
                ;;
        esac
    else
        echo "Dialog cancelled."  
    fi
}

showMenu() {
    # This function is used to show the menu
    local opts=(1 "Install A New Version" 2 "Uninstall A Version" 3 "Show All Versions" 4 "See the NeoPack registry" 5 "Exit")
    CHOICE=$(dialog --menu "Welcome to the Nain Version Manager" 0 0 0 "${opts[@]}" 2>&1 >/dev/tty)
    
    if [ $? -eq 0 ]; then
        case $CHOICE in 
            1)
                installVersion
                ;;
            2)
                echo "Uninstalling a version..."
                ;;
            3)
                echo "Showing all versions..."
                ;;
            4)
                echo "Accessing the NeoPack registry..."
                ;;
            5)
                echo "Exiting..."
                ;;
            *)  # Catch-all case for unexpected input
                echo "Invalid option selected."
                ;;
        esac
    else
        echo "Dialog cancelled."  # Handle dialog cancellation
    fi
    clear
}

showMenu
