function fetchBookTitle() {
    return new Promise((resolve) => {
        resolve("Crime and Punishment")
    });
}

function fetchAuthorDetails() {
    return new Promise((resolve) => {
        resolve("Fyodor Dostoevsky");
    });
}

function fetchPublicationInfo(error) {
    return new Promise((resolve, reject) => {

        resolve("03.04.1927");
        reject(error);
    });
}

function getBookDetails() {
    Promise.all([
        fetchBookTitle(),
        fetchAuthorDetails(),
        fetchPublicationInfo(true)
    ]).then(result => console.log(result))
        .catch(err => console.log(err))
            .finally(() => console.log("processed"));
}

getBookDetails();
