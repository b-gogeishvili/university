ქვიზი - 3
Dimitri Beradze
•
May 30, 2024 (Edited May 30, 2024)
15/15
15 points out of possible 15
Due May 30, 2024, 3:02 PM
quizz_3.js
Javascript
Class comments
Your work
Graded
first.js
Javascript
second.js
Javascript
2 private comments
Dimitri BeradzeMay 30, 2024
1. 4 + 1(ბონუსი) / 5

resolve("03.04.1927");
reject(error);

აქ პირობა აკლია

if (error) { reject } else { resolve } ეს არის სწორი ფორმა

2. 10/10

აქვს ხარვეზები მაგრამ არაუშავს

("click", imgAppend) ეს უნდა გეწეროს და არა

("click", imgAppend()) - ეს ერთხელ გამოიძახება და კლიკს მერე ვერ აღიქვამს
Dimitri BeradzeMay 30, 2024
გადახედეთ შეფასებას, კვირის ბოლოს ავსახავ უწყისში. 

წარმატებები

async function getPic() {
    let responseData = await fetch("https://dog.ceo/api/breeds/image/random");

    let jsonData = await responseData.json();

    return jsonData.message;
}

document.getElementById("button").addEventListener("click", imgAppend());

function imgAppend() {
    let container = document.getElementById("image-container");

    let img = document.createElement("img");
    getPic().then( function(result) {
        img.src = result;
        img.style = "200px 200px";
    });

    container.appendChild(img);
}
