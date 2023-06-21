# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
<<<<<<< HEAD
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/09/01 23:45:16 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='ft_atoi_base.c'
ASSIGN='ft_atoi_base'

bash .system/auto_correc_main.sh $FILE $ASSIGN "Ceci permet de decouvrir le fonctionnement de ton ft_atoi_base." "16"
=======
<<<<<<< HEAD
#    By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2023/02/21 01:29:54 by nnuno-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='ft_range.c'
ASSIGN='ft_range'

bash .system/auto_correc_main.sh $FILE $ASSIGN "1" "3"
=======
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/09/01 23:45:10 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='expand_str.c'
ASSIGN='expand_str'

bash .system/auto_correc_program.sh $FILE $ASSIGN 
>>>>>>> rht
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

<<<<<<< HEAD
bash .system/auto_correc_main.sh $FILE $ASSIGN "-1" "2"
=======
bash .system/auto_correc_program.sh $FILE $ASSIGN  "See? It's easy to print the same thing"
>>>>>>> rht
>>>>>>> 6c13fe5618ff81e6322af184600f0fed1503d01a
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

<<<<<<< HEAD
bash .system/auto_correc_main.sh $FILE $ASSIGN "13268!" "16"
=======
<<<<<<< HEAD
bash .system/auto_correc_main.sh $FILE $ASSIGN "0" "0"
=======
bash .system/auto_correc_program.sh $FILE $ASSIGN " this        time it      will     be    more complex  . "
>>>>>>> rht
>>>>>>> 6c13fe5618ff81e6322af184600f0fed1503d01a
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

<<<<<<< HEAD
bash .system/auto_correc_main.sh $FILE $ASSIGN "-13268!" "10"
=======
<<<<<<< HEAD
bash .system/auto_correc_main.sh $FILE $ASSIGN "0" "-3"
=======
bash .system/auto_correc_program.sh $FILE $ASSIGN  "No S*** Sherlock..." "nAw S*** ShErLaWQ..."
>>>>>>> rht
>>>>>>> 6c13fe5618ff81e6322af184600f0fed1503d01a
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

<<<<<<< HEAD
=======
<<<<<<< HEAD

bash .system/auto_correc_main.sh $FILE $ASSIGN "1" "2"
=======
bash .system/auto_correc_program.sh $FILE $ASSIGN "comme c'est cocasse" "vous avez entendu, Mathilde ?"
>>>>>>> rht
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

<<<<<<< HEAD
bash .system/auto_correc_main.sh $FILE $ASSIGN "3" "8"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh $FILE $ASSIGN "-1" "2932"
=======

bash .system/auto_correc_program.sh $FILE $ASSIGN "5"
>>>>>>> rht
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

<<<<<<< HEAD
bash .system/auto_correc_main.sh $FILE $ASSIGN "-13" "2932"
=======
bash .system/auto_correc_program.sh $FILE $ASSIGN "Too" "Many" "Arguments"
>>>>>>> rht
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

<<<<<<< HEAD
bash .system/auto_correc_main.sh $FILE $ASSIGN "0" "2932"
=======
bash .system/auto_correc_program.sh $FILE $ASSIGN "7"
>>>>>>> rht
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

<<<<<<< HEAD



=======
>>>>>>> rht
>>>>>>> 6c13fe5618ff81e6322af184600f0fed1503d01a
touch .system/grading/passed;
