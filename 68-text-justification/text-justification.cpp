class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        while (i < words.size()) {
            vector<string> currentLine = getWords(i, words, maxWidth);
            i += currentLine.size();
            ans.push_back(createLine(currentLine, i, words, maxWidth));
        }
        return ans;
    }

private:
    vector<string> getWords(int i, vector<string>& words, int maxWidth) {
        vector<string> currentLine;
        int currLength = 0;
        while (i < words.size() && currLength + words[i].size() <= maxWidth) {
            currentLine.push_back(words[i]);
            currLength += words[i].size() + 1;
            i++;
        }
        return currentLine;
    }
    string createLine(vector<string>& line, int i, vector<string>& words,
                      int maxWidth) {
        int baseLength = -1;
        for (const string& word : line) {
            baseLength += word.size() + 1;
        }
        int extraSpaces = maxWidth - baseLength;
        if (line.size() == 1 || i == words.size()) {
            string res = join(line, " ");
            res += string(extraSpaces, ' ');
            return res;
        }
        int wordCount = line.size() - 1;
        int spacesPerWord = extraSpaces / wordCount;
        int needsExtraSpace = extraSpaces % wordCount;
        for (int j = 0; j < needsExtraSpace; j++) {
            line[j] += " ";
        }
        for (int j = 0; j < wordCount; j++) {
            line[j] += string(spacesPerWord, ' ');
        }
        return join(line, " ");
    }
    string join(vector<string>& line, const string& delimeter) {
        if (line.empty()) {
            return "";
        }
        string res(line[0]);
        for (int i = 1; i < line.size(); i++) {
            res += delimeter + line[i];
        }
        return res;
    }
};