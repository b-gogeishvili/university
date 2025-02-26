import './product-card.js';

class ProductList extends HTMLElement {
    constructor() {
        super();
        this.attachShadow({ mode: 'open' });
        this.shadowRoot.innerHTML = `
            <style>
                .list {
                    display: flex;
                    flex-direction: column;
                    max-width: 600px;
                }
            </style>
            <div class="list"></div>
        `;

        this.products = [];
        this.users = [];
    }

    async connectedCallback() {
        await this.fetchData();
        this.render();
    }

    async fetchData() {
        const [products, users] = await Promise.all([
            fetch('https://fakestoreapi.com/products').then(res => res.json()),
            fetch('https://jsonplaceholder.typicode.com/users').then(res => res.json())
        ]);

        this.products = products.slice(0, 10);
        this.users = users.slice(0, 10);

        const userReviews = this.users.map(user => ({
            name: user.name,
            email: user.email
        }));

        this.products = this.products.map(product => ({
            ...product,
            image: 'https://picsum.photos/200',
            reviews: userReviews
        }));
    }

    render() {
        const list = this.shadowRoot.querySelector('.list');
        list.innerHTML = '';
        this.products.forEach(product => {
            const productCard = document.createElement('product-card');
            productCard.setAttribute('title', product.title);
            productCard.setAttribute('price', product.price);
            productCard.setAttribute('image', product.image);
            productCard.setAttribute('reviews', JSON.stringify(product.reviews));
            list.appendChild(productCard);
        });
    }
}

customElements.define('product-list', ProductList);
