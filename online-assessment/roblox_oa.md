Imagine a conversation between two users in a chat app. Given a two-dimensional string array messages representing messages from each user, your task is to render the conversation in a messenger window. Specifically, messages[i] represents the ith message in the conversation in the following format: [<user>, <text>]. Note that messages[i][0] is either "1" or "2" to describe which user sent the message.

To render the messenger window, each message must start on a new line. You are also given two integers width and userWidth, where width represents the width of the entire messenger window, and userWidth represents the maximum number of characters that can be rendered on each line of the conversation. Messages which exceed userWidth should be rendered on multiple lines. Words in the message are not allowed to be split in the middle, and it is guaranteed that no word in the message has length exceeding userWidth.

In the messenger window, messages from user "1" should be aligned to the left, and messages from user "2" should be aligned to the right.

To visualize the messenger window, enclose the conversation into a frame with vertical bars and asterisks. The leftmost and rightmost sides of the frame should have vertical bars (the | character), and the topmost and bottommost lines of the frame should have asterisks - a string of * symbols (with length of width) and 2 + symbols on the edges (aligned with the vertical bars |).

The example below provides more details.

Note: You are not expected to provide the most optimal solution, but a solution with time complexity not worse than O(messages.length · messages[0][1].length · width) will fit within the execution time limit.

Example

For

messages = [["1", "Hello how r u"],
            ["2", "good ty"],
            ["2", "u"],
            ["1", "me too bro"]]
width = 15, and userWidth = 5, the output should be

solution(messages, width, userWidth) = ["+***************+",
                                        "|Hello          |",
                                        "|how r          |",
                                        "|u              |",
                                        "|           good|",
                                        "|             ty|",
                                        "|              u|",
                                        "|me             |",
                                        "|too            |",
                                        "|bro            |",
                                        "+***************+"]
Note that the character "u" from the first message has been moved to a new line as there wasn't enough space on the previous line because of userWidth = 5.
Note that line "how r" contains 4 characters, and the next line does not start with a space because spaces should be eliminated when a new line starts.
Input/Output

[execution time limit] 0.5 seconds (cpp)

[memory limit] 1 GB

[input] array.array.string messages

An array of string arrays representing messages from a conversation between 2 users. No word in any message has length exceeding userWidth.

Guaranteed constraints:
1 ≤ message.length ≤ 50,
messages[i].length = 2,
1 ≤ messages[i][j].length ≤ 350.

[input] integer width

An integer representing the width of the entire frame.

Guaranteed constraints:
5 ≤ width ≤ 100.

[input] integer userWidth

An integer representing the width of character limits for each line/message in the frame.

Guaranteed constraints:
4 ≤ userWidth < width.

[output] array.string

Return the rendered messenger window as array of strings, in which the ith string represents the ith line of the messenger.

[C++] Syntax Tips

// Prints help message to the console
// Returns a string
string helloWorld(string name) {
    cout << "This prints to the console when you Run Tests" << endl;
    return "Hello, " + name;
}