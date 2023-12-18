import os
import random

ignore_files = ["scripts", ".github", ".git", ".gitignore"]

github_username = "Geoffrey-Anto"


def getProblemName(problem: str):
    return problem.replace("-", " ").replace("_", " ").title()


def getLeetcodeProblemLink(problem: str):
    return problem.replace("_", "-").replace("'", "")


def getProblemLinkWithNameAndDescription(problem: str):
    return f"Problem Link: [{getProblemName(problem)}](https://leetcode.com/problems/{getLeetcodeProblemLink(problem)}/) - Solution: [Solution](https://github.com/{github_username}/leetcode-solutions/tree/main/problems/{problem})\n"


def main():
    problems = os.listdir("./problems")

    for ignore_file in ignore_files:
        if ignore_file in problems:
            problems.remove(ignore_file)

    with open("scripts/readme_templates_generated/Readme.md", "a+") as readmeWriter:
        for idx, problem in enumerate(problems, start=1):
            readmeWriter.write(
                f"{idx}.  {getProblemLinkWithNameAndDescription(problem)}\n")


if __name__ == "__main__":
    main()
