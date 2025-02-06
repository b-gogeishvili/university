# დაწერეთ კლასი, სახელად ABC, რომელიც დაამუშავებს სტრინგს. კლასს უნდა
# ჰქონდეს კონსტრუქტორი, პრინტი და ამოცანის შესაბამისი სხვა მეთოდები:
#
# 1. გაწერეთ მეთოდი abbreviation, რომელიც დააბრუნებს სტრინგის აბრევიატურას (მაგ.
# Caucasus University=> CU).
#
# 2. გაწერეთ მეთოდი reverse, რომელიც სტრინგს შეაბრუნებს (მაგ. Hello CU => UC olleH).
# გაითვალისწინეთ, სორტირების გამოყენება არ შეგიძლიათ.
#
# 3. გაწერეთ მეთოდი trim, რომელიც სტრინგთან ერთად არგუმენტად მიიღებს რიცხვს,
# წინადადებიდან დატოვებს გადაცემული რიცხვის რაოდენობის საწყის სიმბოლოს,
# ხოლო დანარჩენს წაშლის და ჩაანაცვლებს წერტილით (მაგ. Hello CU, 4 => Hell...).
#
# 4. გაწერეთ მეთოდი mydic, რომელიც ლექსიკონში სტრინგის თითოეული სიმბოლოს
# შესაბამის კოდს ASCII-ის ცხრილიდან დაამატებს გასაღების სახით, რომლის
# მნიშვნელობა იქნება სიმბოლოს მდებარეობა ანბანში. იმ შემთხვევაში, თუ სიმბოლო
# მეორდება, მაშინ გასაღების მნიშვნელობა უნდა იყოს კორტეჟი, სადაც ჩაიწერება
# სიმბოლოების პოზიცია ანბანში და მათი რაოდენობა. სიმბოლოების, რომლებიც არ
# გვხდებიან ანბანში, მნიშვნელობა უნდა იყოს 0. (მაგ. Hello CU => {72:8, 101:5, 108:(12, 2),
# 111:15, 32:0, 67:3, 85:21}).

# Hello CU => {
#   72:8,
#   101:5,
#   108:(12, 2),
#   111:15,
#   32:0,
#   67:3,
#   85:21
# })

class ABC:
    def __init__(self, string):
        self.name = string

    def __str__(self):
        return f"Class ABC: {self.name}"

    def abbreviation(self):
        # List Comprehension-ის გამოყენებით ვიღებ თითოეული სიტყვის პირველ ასოს
        str_split = [word[0] for word in self.name.split(" ")]
        res = ""

        # შემდეგ გადავუყვები თითოეულს და გარდავქმნი სტრინგად
        for each in str_split:
            res += each

        return res

    def reverse(self):
        return self.name[::-1]

    def trim(self, n):
        # ვადგენ დასამატებელი წერტილების რაოდენობას
        dots = "." * (len(self.name) - n)

        return self.name[:n] + dots

    def mydic(self):
        dic = {}
        for letter in self.name:
            # ord() ფუნქციის საშუალებით ვიგებ char-ის რიცხვით მნიშვნელობას ASCII-ის მიხედვით
            # ვაკლებ 64 თუ დიდი ასოა, სხვა შემთხვევაში 96
            letter_pos = ord(letter) - (64 if letter.isupper() else 96)

            # ვითვალისწინებ space-ებს და სხვა არა ანბანში შემავალ ასოებს
            if not letter.isalpha():
                letter_pos = 0

            try:
                val = dic[ord(letter)]

                if type(val) is tuple():
                    letter_count = len(list(val))
                    lst = list(val) + letter_count
                else:
                    letter_count = 2
                    lst = [val, letter_count]

                dic[ord(letter)] = tuple(lst)
            except KeyError:
                dic[ord(letter)] = letter_pos

        return dic


instance = ABC("Hello CU")
print(instance)
print(instance.abbreviation())
print(instance.reverse())
print(instance.trim(4))
print(instance.mydic())
