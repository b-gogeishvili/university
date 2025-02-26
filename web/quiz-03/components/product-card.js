import './review-card.js';

class ProductCard extends HTMLElement {
    constructor() {
        super();
        this.attachShadow({ mode: 'open' });
        this.shadowRoot.innerHTML = `
            <style>
                .card {
                    border: 1px solid #ccc;
                    border-radius: 8px;
                    padding: 16px;
                    margin: 8px;
                    background-color: #fff;
                    box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
                    display: flex;
                    flex-direction: column;
                    align-items: center;
                }
                .image {
                    border-radius: 8px;
                    margin-bottom: 16px;
                }
                .title {
                    font-size: 1.2em;
                    margin: 0;
                    text-align: center;
                }
                .price {
                    font-size: 1em;
                    color: #666;
                    text-align: center;
                }
                .reviews {
                    width: 100%;
                    margin-top: 16px;
                }
            </style>
            <div class="card">
                <img class="image" src="" alt="Product Image" width="100" height="100">
                <p class="title"></p>
                <p class="price"></p>
                <div class="reviews"></div>
            </div>
        `;
    }

    connectedCallback() {
        this.shadowRoot.querySelector('.title').textContent = this.getAttribute('title');
        this.shadowRoot.querySelector('.price').textContent = `$${this.getAttribute('price')}`;
        this.shadowRoot.querySelector('.image').src = this.getAttribute('image');

        const reviewsContainer = this.shadowRoot.querySelector('.reviews');
        const reviews = JSON.parse(this.getAttribute('reviews'));
        reviews.forEach(review => {
            const reviewCard = document.createElement('review-card');
            reviewCard.setAttribute('name', review.name);
            reviewCard.setAttribute('email', review.email);
            reviewsContainer.appendChild(reviewCard);
        });
    }
}

customElements.define('product-card', ProductCard);
