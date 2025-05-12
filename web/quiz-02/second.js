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
