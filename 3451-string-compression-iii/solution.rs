impl Solution {
    pub fn compressed_string(word: String) -> String {
        let mut answer = String::new();

        let mut count: i8 = 1;
        let mut prev = word.chars().nth(0).unwrap();

        for (i, ch) in word.chars().enumerate() {
            if i == 0 {
                continue;
            } else {
                if i == 1 && prev != ch {
                    answer += "1";
                    answer += &prev.to_string();
                    prev = ch;
                } else {
                    if prev != ch {
                        answer += &count.to_string();
                        answer += &prev.to_string();

                        prev = ch;
                        count = 1;
                    } else {
                        if count == 9 {
                            answer += &count.to_string();
                            answer += &prev.to_string();

                            prev = ch;
                            count = 0;
                        }

                        prev = ch;
                        count = count + 1;
                    }
                }
            }
        }

        answer += &count.to_string();
        answer += &prev.to_string();

        return answer;
    }
}
