
typedef char *arrayString;


char characterAt(arrayString s, int pos)
{
	return s[pos];
}


int length(arrayString s)
{
	int i = 0;
	while (characterAt(s, i) != 0)
	{
		i += 1;
	}

	return i;
}


bool equals(arrayString &s1, arrayString &s2)
{
	int len = length(s1);

	if (len != length(s2)) return false;

	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (s1[i] != s2[i]) return false;
	}
	return true;
}


void append(arrayString &s, char c)
{
	int oldLength = length(s);
	
	arrayString newString = new char[oldLength + 2];  // create a larger array
	
	for (int i = 0; i < oldLength; i++)
	{
		newString[i] = s[i];  // initialize new string with old string data
	}

	newString[oldLength] = c;
	newString[oldLength + 1] = 0;

	delete[] s;  // delete the original string data
	s = newString;  // point to newly created string
}


void concatenate(arrayString &s1, arrayString &s2)
{
	int s1Length = length(s1);
	int s2Length = length(s2);
	int newLength = s1Length + s2Length;

	arrayString newString = new char[newLength + 1];

	for (int i = 0; i < s1Length; i++)  // Add first string to new string
	{
		newString[i] = s1[i];
	}

	for (int i = 0; i < s2Length; i++)  // Add second string to new string
	{
		newString[s1Length + i] = s2[i];
	}

	newString[newLength] = 0;  // Terminate the new string
	delete[] s1;  // Delete the unused data of the first string
	s1 = newString;  // Point to the new string
}


arrayString substring(arrayString &s, int start, int length)
{
	arrayString newString = new char[length + 1];
	int i = 0;
	for (i = 0; i <= length; i++)
	{
		newString[i] = s[start + i];
	}
	newString[length] = 0;
	return newString;
}



arrayString replaceString(arrayString &source, arrayString target, arrayString replaceText)
{
	arrayString newString = new char[1];
	newString[0] = 0;

	int sLen = length(source);
	int tLen = length(target);

	arrayString sub = new char[tLen + 1];
	int i = 0;
	for (i = 0; i <= sLen - tLen; i++)
	{
		sub = substring(source, i, tLen);

		if (equals(sub, target))
		{
			concatenate(newString, replaceText);
		}
		else
		{
			append(newString, source[i]);
		}
	}
	return newString;
}