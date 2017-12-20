export CLICOLOR=1
# Couleurs dans le terminal :
# Format :
#	\[\033[0;COLOR_CODE\] texte \[\033[0m\]
# Codes couleur (COLOR_CODE) :
# 30m : Noir
# 31m : Rouge
# 32m : Vert
# 33m : Jaune
# 34m : Bleu
CWHITE="\[\033[30m\]"	# Color : white
CBLACK="\[\033[30m\]"	# Color : black
CRED="\[\033[31m\]"	# Color : red
CGREEN="\[\033[32m\]"	# Color : green
CYELLOW="\[\033[33m\]"	# Color : yellow
CBLUE="\[\033[34m\]"	# Color : blue

BBLACK="\[\033[40m\]"	# Color : black
BRED="\[\033[41m\]"	# Color : red
BGREEN="\[\033[42m\]"	# Color : green
BYELLOW="\[\033[43m\]"	# Color : yellow
BBLUE="\[\033[44m\]"	# Color : blue

DEFBACK="\[\033[0m\]" 	# Color : default

export PS1="$BBLUE $CRED\d, \t $DEFBACK $CRED\u$DEFBACK$BBLUE$CRED@$DEFBACK$CGREEN\h$DEFBACK $BBLUE$CRED:\w $DEFBACK\n$CRED $ $DEFBACK"
export PS2="$BBLUE \d, \t $DEFBACK /> "

test -e "${HOME}/.iterm2_shell_integration.bash" && source "${HOME}/.iterm2_shell_integration.bash"
