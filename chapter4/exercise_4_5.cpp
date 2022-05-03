void removeRecord(studentCollection& sc, int num)
{
    studentCollection tempCollec = sc;

    //Node for removal is head
    if(tempCollec->studentNum == num)
    {
        //Redirect
        sc = tempCollec->next;

        //Deallocate
        delete tempCollec;
    }
    else //Node to remove is in the middle or at the end
    {
        while(tempCollec != nullptr)
        {
            if(tempCollec->next->studentNum == num)
            {
                //Redirect
                tempCollec->next = tempCollec->next->next;

                //Exit
                break;
            }
            tempCollec = tempCollec->next;
        }
    }
}
