class Solution {
public:
    string convertToTitle(int columnNumber) {
        string output;

        if (columnNumber % 26 == 0)
        {
            int count = 0;
            while (columnNumber > 26)
            {
                count++;
                columnNumber -= 26;
            }
            
            if (count > 26) { output = buildTitle(count);  }
            else { if (count > 0) { output += static_cast<char>(count + 64); } }

            output += 'Z';

            return output;
        }
        else
        {
            output += buildTitle(columnNumber);
        }

        return output;
    }

    string buildTitle(int n)
    {
        int remember = 0, top = 0, cal = 0;
        string title;
        stack<int> lifo;
        lifo.push(n);

        while (n > 26)
        {
            if (n % 26 == 0) { lifo.push(n / 26 - 1); n = n / 26 - 1; continue; }
            n /= 26;
            if (n > 0) { lifo.push(n); }
        }

        while (!lifo.empty())
        {
            top = lifo.top();
            if (top <= 26)
            {
                title += static_cast<char>(top + 64);
            }
            else
            {
                cal = top - 26 * remember;
                title += static_cast<char>(cal + 64);
            }

            remember = top;
            lifo.pop();
        }

        return title;
    }
};