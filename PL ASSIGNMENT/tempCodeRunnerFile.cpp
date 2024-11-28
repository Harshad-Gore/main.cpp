void insert(int key)
    {
        int index = hashFunction(key);
        int i = 0;
        while (table[(index + i * i) % SIZE] != -1)
        {
            i++;
        }
        table[(index + i * i) % SIZE] = key;
    }