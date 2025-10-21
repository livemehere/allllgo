#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, int> email_to_id;
        unordered_map<int, string> id_to_name;
        int id = 0;

        // Step 1: Assign IDs to emails and map names
        for (const auto &account : accounts)
        {
            const string &name = account[0];
            for (size_t i = 1; i < account.size(); ++i)
            {
                const string &email = account[i];
                if (email_to_id.find(email) == email_to_id.end())
                {
                    email_to_id[email] = id;
                    id_to_name[id] = name;
                    ++id;
                }
            }
        }

        // Step 2: Union-Find structure
        vector<int> parent(id);
        for (int i = 0; i < id; ++i)
            parent[i] = i;

        function<int(int)> find = [&](int x)
        {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        };

        auto union_sets = [&](int a, int b)
        {
            int rootA = find(a);
            int rootB = find(b);
            if (rootA != rootB)
                parent[rootB] = rootA;
        };

        // Step 3: Union emails in the same account
        for (const auto &account : accounts)
        {
            int first_email_id = email_to_id[account[1]];
            for (size_t i = 2; i < account.size(); ++i)
            {
                int email_id = email_to_id[account[i]];
                union_sets(first_email_id, email_id);
            }
        }

        // Step 4: Group emails by their root parent
        unordered_map<int, vector<string>> groups;
        for (const auto &[email, eid] : email_to_id)
        {
            int root_id = find(eid);
            groups[root_id].push_back(email);
        }

        // Step 5: Prepare the result
        vector<vector<string>> result;
        for (const auto &[root_id, emails] : groups)
        {
            vector<string> account;
            account.push_back(id_to_name[root_id]);
            vector<string> sorted_emails = emails;
            sort(sorted_emails.begin(), sorted_emails.end());
            account.insert(account.end(), sorted_emails.begin(), sorted_emails.end());
            result.push_back(account);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}};
    vector<vector<string>> result = s.accountsMerge(accounts);
    for (const auto &account : result)
    {
        for (const auto &email : account)
        {
            cout << email << " ";
        }
        cout << endl;
    }
    return 0;
}