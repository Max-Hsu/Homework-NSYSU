cd
ln -s /dev/null X &> /dev/null
rm -r HW2 &>~/X
tar xvf HW2.tar >~/X
ln -s HW2 G &>~/X
ln -s G/obj O &>~/X
ln -s G/inv I &>~/X
cd HW2/street
PS1=">"
alias l='cd - >~/X;cat .???*;ls *\ * 2>~/X|fgrep " ";cd ->~/X'
alias see='(mv ~/G/tmpD ~/G/tmpC>~/X;pwd>~/G/tmpD;diff -q ~/G/tmp[CD]>~/X&&echo You cannot go that way.||(cat .?[^o]*&&mv .description?2 .done2;ls *\ *|cat))2>~/X;cd ~/G/obs'

alias board='cd ->~/X;ls train&>~/X&&cd ~/G/museum;see;(cd -;rm .desc*A0)&>~/X'
alias ne='cd ->~/X;cd ne 2> ~/X; see'
alias se='cd ->~/X;cd se 2> ~/X; see'
alias nw='cd ->~/X;./nw 2> ~/X|| see'

alias GB='basename `pwd -P`>~/G/tmpB&&diff -q ~/G/tmp[AB]&>~/X&&cd `pwd -P`/..'
alias sw='cd ->~/X;echo ne>~/G/tmpA &&GB && see'
alias u=' cd ->~/X;echo d >~/G/tmpA &&GB ||cd u 2> ~/X; see'
alias d=' cd ->~/X;echo u >~/G/tmpA &&GB ||cd d 2> ~/X; see'
alias w=' cd ->~/X;echo e >~/G/tmpA &&GB ||cd w 2> ~/X; see'
alias s=' cd ->~/X;echo n >~/G/tmpA &&GB ||cd s 2> ~/X; see'
alias e=' cd ->~/X;echo w >~/G/tmpA &&GB ||cd e 2> ~/X; w/e 2>~/X&&cd w||see'
alias n=' cd ->~/X;echo s >~/G/tmpA &&GB ||cd n 2> ~/X; s/n 2>~/X&&cd s||see'

alias i='(echo You currently have:; cd ~/G/inv; ls [^Tj]* | cat -n |\
      tr "\t\n[0-9]" "** ">~/G/i;cd ~/G/invNames;ls `cat ../i`;\
      ls ~/G/inv/jar >~/X && ls *jar*|cat)2>~/X|fgrep " "'

alias Arg2File='cat>../T&&cd - >~/X;rm -f ~/O/*&>~/X'
alias InRoom='Arg2File; cp `cat ~/G/T`                     ~/O &>~/X'
alias FromInv='Arg2File;mv             ~/G/inv/`cat ~/G/T` ~/O &>~/X'
alias InArea='Arg2File; cp `cat ~/G/T` ~/G/inv/`cat ~/G/T` ~/O &>~/X'

alias x='(InArea;cat ~/O/* 2>~/X||echo I do not see that here.) <'

see
