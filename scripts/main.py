import os

ignore_files = ["scripts", ".github", ".git", ".gitignore"]


def main():
    problems = os.listdir("./")

    for ignore_file in ignore_files:
        if ignore_file in problems:
            problems.remove(ignore_file)

    for idx, problem in enumerate(problems, start=1):
        print(f"{idx} {problem}...")


if __name__ == "__main__":
    main()
