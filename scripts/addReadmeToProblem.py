import os
import random

ignore_files = ["scripts", ".github", ".git", ".gitignore"]

github_username = "Geoffrey-Anto"


def getProblemName(problem: str):
    return problem.replace("-", " ").replace("_", " ").title()


def convertFileTypeToLanguage(fileType):
    if fileType == "py":
        return "Python"
    elif fileType == "cpp":
        return "C++"
    elif fileType == "js":
        return "JavaScript"
    elif fileType == "go":
        return "GoLang"
    elif fileType == "java":
        return "Java"
    else:
        return "Unknown"


def getLeetcodeProblemLink(problem: str):
    return problem.replace("_", "-").replace("'", "")


def main():
    problems = os.listdir("./problems")

    for ignore_file in ignore_files:
        if ignore_file in problems:
            problems.remove(ignore_file)

    for idx, problemFolder in enumerate(problems, start=1):
        with open(f"problems/{problemFolder}/README.md", "w+") as readmeWriter:
            filesInProblemFolder = os.listdir(f"problems/{problemFolder}")
            for file in filesInProblemFolder:
                if file.endswith(".md"):
                    continue
                else:
                    readmeWriter.write(
                        f"# {getProblemName(problemFolder)}\n\n")
                    readmeWriter.write(
                        f"## Leetcode Link: [{getProblemName(problemFolder)}](https://leetcode.com/problems/{getLeetcodeProblemLink(problemFolder)}/)\n")
                    readmeWriter.write(
                        f"### Language: {convertFileTypeToLanguage(file.split('.')[-1])}\n\n"
                    )
                    with open(f"problems/{problemFolder}/{file}", "r") as fileReader:
                        readmeWriter.write(f"```{file.split('.')[-1]}\n")
                        readmeWriter.write(fileReader.read())
                        readmeWriter.write(f"```\n\n")
                        readmeWriter.write("\n\n")


if __name__ == "__main__":
    main()
