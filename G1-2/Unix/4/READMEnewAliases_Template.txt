Let us discuss how to run the previously provided tar file. You put the tar
file in your home directory and then you type this:

% tar -xvf HW4.tar
% cp HW4/pa3into pa4
% sh
$ source ./pa4
Fourth-Vermont intersection
You are at the intersection of Fourth Street and Vermont Ave.
>

At this point you should be able to play the solution to the previous homework.
(You should use my version, not your own, because it is modified slightly to
work with the new directory structure.)


-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -

Your job is to add three new aliases (cheat, score and type) into the pa4 file.

First, add cheat. It's easy to add, because I give it to you. Paste in this:

alias cheat='(mv ~/G/rooms/museum/n/n/d/amethyst ~/G/inv; rm ~/G/rooms/museum/n/n/d/*amethyst*; mv ~/G/rooms/street/e/s/coins ~/G/inv; rm ~/G/rooms/street/e/s/*coins*; cd ~/G/rooms/endgame; cd -; drop amethyst;drop coins;drop silver; drop ruby; drop egg)&>~/X'

As you can see, it just gets and drops treasures.

-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -

Second, add type. It looks like this:

alias type='__1__ && cd ~/G/rooms/endgame && cat .???*;ls *\ * 2>~/X|fgrep " " && rm .d*0 && mv .d*2 .doneZ2 && pwd > ~/G/tmpD && echo "endgame points out of a possible 110." > ~/G/scoremsg && cd ~/G/obs'
  __1__: This runs the type script that you will write. It passes the score
         message in as the argument list to the type script. This is done by
         running the score alias.

  The rest of the line runs some of the operations from the l and see aliases.
  It also cleans up some files. All of this only executes if the type script
  returns success. (And your type script will return success in the case that
  you have logged into endgame successfully.)  

The reason that there isn't more work to do is that most of the work of the
assignment is to implement the type cshell script, which isn't one of the
aliases in the pa4 file.

Obviously, we cannot test the type alias without creating the type script.

So, to test it, we can make a temporary script:

% echo "exit 0" > ~/type
% chmod u+x ~/type
% sh
$ source ./pa4
Fourth-Vermont intersection
You are at the intersection of Fourth Street and Vermont Ave.
$ type
-bash: score: command not found
$

Right, because we didn't make score yet. That's the next step:

-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -

Third, add score. It looks like this:

alias score='(cd ~/G/rooms/endgame;ls [^Tn]* | grep "__1__"$ | sed __2__; echo) | sed -n "__3__;__4__"|sed "__5__"'

  cd ~/G/rooms/endgame: We go to this directory so that we can see what is in
            treasure room.

  ls [^Tn]*:This will prevent files like 'There is a gold bar here.' from
            listing. It also avoids going into the n subdirectory.

  __1__:    This regular expression must match to the 11 treasures (amethyst,
            bill, bracelet, coins, diamond, egg, gold, mona, platinum, ruby,
	    and silver), but to none of the other movable items (acid, bone,
	    glycerine, jar, key, lamp, license, paper, preserver, shovel, and
	    towel). Note that, as I've indicated, the pattern is in double
	    quotes (because the defining of the alias already uses the single
            quotes, and I've indicated that the pattern ends with a $. (I've
	    placed the $ outside of the quotes to avoid confusion. As we've
	    seen in class, cshell doesn't accept things like "...$", because
	    the " after the $ looks like a bad variable name. When put outside
            the quotes, however, there is no problem. Now there is, in fact no
            problem with doing "...$" anyway, because the aliases are running
            in bash, not csh. But, regardless, I've used the "..."$ because it
            works for both shells and therefore avoids the shell issue.

  __2__:    This is a sed program. It creates the same output as wc -l would
            create. Note that this outputted number indicates the number of 
            treasures in the treasure room.
            Note also that 0 is a special case (and it is possible for there
            to be 0 treasures, if the player picks them all up from the 
            treasure room). What makes 0 a special case is that the __1__ 
            would produce no output, so the sed __2__ program would never run.

  echo:     The reason of this is to deal with the aforementioned special case.
            By always echoing an empty line, there are two possible outcomes:
            1) if there are 0 treasures, the empty line prints, or 2) if there
            are 1 or more treasures, two lines print, with the first line 
            holding the number of treasures, and the second line being empty.
            The outcome of all of this is that the first line of output will
            be the number of treasures or empty.
            Since each treasure is worth 10 points, we can say that this the
            top digit of the two digit number for the score (at least, until
            you get the $100 bill or the Mona Lisa). The reason to think in
            terms of the top digit of a two digit number is that the case of
            zero treasures is NOT a two digit number; it is just 0 points --
            hence the empty line.

  (...):    The above steps are enclosed in parentheses, as shown. The purpose
            of the (...) are twofold: 1) to forget the cd ~/G/rooms/endgame
            action performed above, and 2) to allow the outputs generated by 
            the "sed __2__" and by the "echo" to merge into one output stream.

  __3__:    This is a single sed s command which only executes for the first
            input line (ie, the line that holds the number of treasures).
            The purpose of this s command is to put the text "You have scored"
            in front of the number received from the input and to put "0 "
            after that received number. The answer is then printed.

  __4__:    This is a single sed r command which prints the contents of the
            ~/HW4/scoremsg file.

  __5__:    This is a two-command sed program which combines two input lines
            into one output line (ie, the \n is removed). (Now you might think
            that tr -d "\n" would achieve this more easily, but the problem is
            that this would remove two \n's, not one.


-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -


Once you have added score, you can test part of your homework:

% echo "exit 0" > ~/type
% chmod u+x ~/type
% sh
$ source ./pa4
Fourth-Vermont intersection
You are at the intersection of Fourth Street and Vermont Ave.
>score
You have scored 40 out of a possible 90 points.
>
># From the above, see that score has given the right output.
>
>
>
>cheat
>score
You have scored 90 out of a possible 90 points.
>
># From the above, see that score has given the right output.
>
>
>
>type
You have scored 90 out of a possible 90 points.

Welcome to the endgame.  You are a truly noble adventurer.

You step back from the console.

Treasure room
You are in the treasure room. A door leads out to the north.
There are some valuable coins here.
There is a beach towel on the ground here.
There is a gold bar here.
There is a jewel-encrusted egg here.
There is a life preserver here.
There is a platinum bar here.
There is a shimmering diamond here.
There is a shiny brass key here.
There is a shovel here.
There is a silver bar here.
There is a slip of paper here.
There is a valuable amethyst here.
There is a valuable ruby here.
There is an emerald bracelet here.
>
># From the above, see that type behaved as it would when logging into endgame.
>
>
>
>score
You have scored 90 endgame points out of a possible 110.
>
># From the above, see that score has given the right *endgame* output.
>
>
>
>n
Endgame N/S hallway
You are in a north/south hallway.
>n
Question room 1
You are in a north/south hallway.
You have reached a question room.  You must answer a question correctly in
order to get by.  Use the ‘answer’ command to answer the question.
>n
Question room 2
You are in a north/south hallway.
>n
Question room 3
You are in a north/south hallway.
>n
Treasure room
You are in the endgame treasure room. A door leads out to the north, and
a hallway leads to the south.
There is a 100 dollar bill here.
>get bill
Taken.
>n
Winner's room
You are in the winner's room.  A door leads back to the south.
The Mona Lisa is here.
>get mona
Taken.
>s
Treasure room
>s
Question room 3
>s
Question room 2
>s
Question room 1
>s
Endgame N/S hallway
>s
Treasure room
There are some valuable coins here.
There is a beach towel on the ground here.
There is a gold bar here.
There is a jewel-encrusted egg here.
There is a life preserver here.
There is a platinum bar here.
There is a shimmering diamond here.
There is a shiny brass key here.
There is a shovel here.
There is a silver bar here.
There is a slip of paper here.
There is a valuable amethyst here.
There is a valuable ruby here.
There is an emerald bracelet here.
>
># At this point, we now have the last two treasures.
>
>
>drop bill
Dropped.
>drop mona
Dropped.
>score
You have scored 110 endgame points out of a possible 110.
>
># From the above, see that score has given the right output.
># We now want to make sure that no other items are misidentified as treasures.
># So we'll everything:
>drop lamp
Dropped.
>drop jar
Dropped.
>drop glycerine
Dropped.
>drop nitric
Dropped.
>drop bone
Dropped.
>i
You currently have:
A license
>drop license
Dropped.
>score
You have scored 110 endgame points out of a possible 110.
>
># From the above, see that score has given the right output.
># We now want to make sure that the 11 comes from counting the right 11 items.
># So we'll get all of the treasures:
>
>get emerald
Taken.
>get diamond
Taken.
>get bill
Taken.
>score
You have scored 80 endgame points out of a possible 110.
>get mona
Taken.
>get coins
Taken.
>get egg
Taken.
>score
You have scored 50 endgame points out of a possible 110.
>get gold
Taken.
>get silver
Taken.
>get platinum
Taken.
>score
You have scored 20 endgame points out of a possible 110.
>get amethyst
Taken.
>get ruby
Taken.
>score
You have scored 0 endgame points out of a possible 110.
>


Yes it worked. 
The last part of the homework, to be posted later, is for implementing the 
cshell script...
