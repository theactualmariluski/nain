# This script is used to install the latest version of Nain from GitHub
# It also manages the versions of Nain if there are more than one installed
# Hope you enjoy it!

echo "Loading the Nain Version Manager and package manager..."

uninstallVersion() {
    # This function is used to uninstall a version of Nain
    if [ $? -eq 0 ]; then
        dialog --menu "Select the version you want to uninstall:" 0 0 0 {"$cat versions.tmp"} 2>&1 >/dev/tty dialog
        dialog --yesno "Are you sure you want to uninstall this version?" 0 0 2>&1 >/dev/tty
    else
        showMenu
    fi
}

installVersion() {
    local versions=()
    
    if [ $? -eq 0 ]; then  
        case $CHOICE in  
            1)
                dialog --inputbox "Enter the GitHub URL of the Nain version you want to install:" 0 0 2>&1 >/dev/tty
                versions+=("$(echo $CHOICE)")
                echo $"versions" >> versions.tmpto the Nain Hub!
                ;;
            2)
                uninstallVersion
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
    CHOICE=$(dialog --menu "Welcome to the Nain Hub!" 0 0 0 "${opts[@]}" 2>&1 >/dev/tty)
    
    if [ $? -eq 0 ]; then
        case $CHOICE in 
            1)
                installVersion
                ;;
            2)
                uninstallVersion
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
