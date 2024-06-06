class Solution {
public:
  bool isNStraightHand(vector<int> &hand, int groupSize) {
    // To store all the hand values in a sorted order with O(log N) insertion, deletion and accessing
    multiset<int> m_set;

    // Insert all the cards in the multiset
    for (auto i : hand) {
      m_set.insert(i);
    }

    int n = hand.size();

    // If the number of cards is not divisible by the group size
    if (n % groupSize != 0) {
      return false;
    }

    // Number of groups
    int noOfGroups = n / groupSize;

    while (noOfGroups--) {
      int i = 0;

      // Take the first element of the group which is always the smallest since it is a multiset
      auto currentStartElement = m_set.begin();
      int previousValue = *currentStartElement;

      // Remove the first element
      m_set.erase(currentStartElement);

      // Traverse the group till theres no element left or we have traversed the group size
      while (i++ < (groupSize - 1)) {
        // If the group becomes empty before we have traversed the group size its not possible
        if (m_set.empty()) {
          return false;
        }

        // Find the next element which is one greater than the previous element
        auto nextElement = m_set.find((int)(previousValue) + 1);

        // If the element is not found return false
        if (nextElement == m_set.end()) {
          return false;
        }

        // Update the previous element and remove the current element
        previousValue = *nextElement;

        // Remove the element
        m_set.erase(nextElement);
      }
    }

    // Possible to create noOfGroups groups with size groupSize
    return true;
  }
};
