/**
 * ამოცანა - 1 (3_PTS)
 * მოცემულია მასივების მასივი(მატრიცა) - nestedArray
 *
 * თქვენი მიზანია destruction-ის გამოყენებით მეორე მასიიდან ამოიღოთ მეორე და მესამე ელემენტი.
 * მნიშვნელობები უნდა იყოს შენახული შესაბმისად:
 * second: "d" და third: "e"
 */
const nestedArray = [['a', 'b'], ['c', 'd', 'e'], ['f', 'g']];
// Your implementation goes here...
const [first, second, third] = nestedArray[1]

console.log(second, third); // Output: "d" "e"











/**
 * ამოცანა - 2 (5_PTS)
 *
 * მოცემულია მასივი - books
 *
 * თქვენი მიზანია შექმნათ bookIterator, რომელიც იქნება closure ფუნქცია
 * თქვენმა ფუნქციამ ყოველ გამოძახებაზე უნდა დააბრუნოს წიგნის სახელი და ავტორი ქრონოლოგიური თანმიმდვრობით.
 * ქრონოლოგია განისაზღვრება წიგნის გამოცემის წლის მიხედვით.
 *
 * თუ გამოძახების რაოდენობა გასცდა წიგნების რაოდენობას, გამოიტანეთ შესაბამისი(თქვენთვის სასურველი) მესიჯი.
 */

const books = [
  { title: "The Catcher in the Rye", author: "J.D. Salinger", year: 1951 },
  { title: "The Hobbit", author: "J.R.R. Tolkien", year: 1937 },
  { title: "Dune", author: "Frank Herbert", year: 1965 },
  { title: "1984", author: "George Orwell", year: 1949 },
  { title: "To Kill a Mockingbird", author: "Harper Lee", year: 1960 }
];

function bookIterator(books) {
  // Your implementation goes here...
  books.sort((a,b) => a.year - b.year);
  let index = 0;

  return () => {
    if (books[index+1] === undefined) {
      return "Out Of Bounds"
    }

    return books[index++];
  }

}

let getBook = bookIterator(books)

console.log("\n")
console.log(getBook()); // Output: { title: "The Hobbit", author: "J.R.R. Tolkien" }
console.log(getBook()); // Output: { title: "1984", author: "George Orwell" }












/**
 * ამოცანა - 3 (7_PTS)
 *
 * შექმენით 2 კლასი MusicalInstrument და Guitar.
 * გამოიყენეთ OOP-ს პრინციპები.
 *
 * უნდა გვქონდეს ორი მახასიათებელი, ინსტრუმენტის სახელი(Yamaha, Schimmel, Fazioli ა.შ) და ტიპი(string, woodwind, keyboard ა.შ).
 * ინსტრუმენტზე დაკვრა(play მეთოდი) ორივე კლასის გამოყენებით უნდა შეგვეძლოს, მაგრამ აწყობა(tune მეთოდი) მხოლოდ გიტარის ვიცით.
 *
 * თქვენი მიზანია ამ ორი კლასის იმპლემენტაცია.
 *
 * !!!! BONUS POINTS (3-PT) !!!!!
 * დაამატეთ შესაბამისი გეთერები და სეტერეი, აჩვენეთ გამოყენების მაგალითები.
 * გააკეთეთ ისე, რომ გიტარის კლასს არ დასჭირდეს ტიპის გადაცემა.
 *
 */

class MusicalInstrument {
  constructor(name, type) {
    this.name = name;
    this.type = type;
  }

  get getName() {
    return this.name;
  }

  set setName(name) {
    this.name = name;
  }

  play() {
    console.log("Playing music...")
  }

}


class Guitar extends MusicalInstrument {
  constructor(name) {
    super(name, "string")
  }

  tune() {
    console.log("Tuning the Guitar...")
  }
}

console.log("\n")
guitar = new Guitar("Fender")
guitar.setName = "Steinberger"
guitar.play()
guitar.tune()
console.log(guitar.getName)

console.log("\n")
instrument = new MusicalInstrument("Yamaha", "keyboard")
console.log(instrument.getName)
instrument.setName = "Schimmel"
guitar.play()
console.log(instrument.getName)
