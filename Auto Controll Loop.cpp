while {encoder < 10 && go == true)
{
	if (ultra < 24)
	{
		for (int i = 0; i < 2; i++)
		{
			wait(1.0);
			if (ultra > 24)
			{
				go = true;
				break;
			}
			else
			{
				go = false;
			}
		}
	}
	// drive code
}
