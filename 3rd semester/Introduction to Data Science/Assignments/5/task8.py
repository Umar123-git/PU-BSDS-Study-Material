books = []
author_count = {}

n = 0
while n <= 0:
    n = int(input("Enter number of books: "))
    if n <= 0:
        print("Invalid input, try again.")

i = 1
while i <= n:
    print(f"\n-------------------- Book {i} --------------------")
    title = input("Enter book title: ")
    author = input("Enter author name: ")
    category = input("Enter book category: ")
    books.append([title, author, category])


    if author in author_count:
        author_count[author] += 1
    else:
        author_count[author] = 1

    i += 1


print("\n-------------------- Library Summary --------------------")
for author in author_count:
    print(f"Books by {author}: {author_count[author]}")


max_author = max(author_count, key=author_count.get)
print("\nAuthor with the most books:", max_author, "with", author_count[max_author], "books")