int    ft_strcmp(char *s1, char *s2)
{
<<<<<<< HEAD
	int i = 0;

	while(s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return(s1[i] - s2[i]);
}
=======
<<<<<<< HEAD
    int i = 0;

    while(s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return(s1[i] - s2[i]);
}
=======
	while(*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return(*s1 -*s2);
}
>>>>>>> rht
>>>>>>> 6c13fe5618ff81e6322af184600f0fed1503d01a
