 
int cmpstr(char* s1, char* s2)
{
  int i=0;
  while(s1[i])
  {
    if(s1[i]!=s2[i])
      break;
    i++;  
  }
  if(s1[i]>s2[i])
    return 1;
  if(s1[i]<s2[i])
    return 2;
  
  return 0;
}