void normalizefeed(char line [])
{
    line.replace(" ","");
    for (int i=0;i<line.length();i++)
    {
        if (line[i]=='F')
        {
            line[i+1]=6;
            line[i+2]=0;
            line[i+3]=0;
            
        }
    }

}